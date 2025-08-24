#include <algorithm>
#include <atomic>
#include <chrono>
#include <iostream>
#include <limits>
#include <thread>
#include <vector>

#include "CRC32.hpp"
#include "IO.hpp"

/// @brief Переписывает последние 4 байта значением value
void replaceLastFourBytes(std::vector<char> &data, uint32_t value) {
  std::copy_n(reinterpret_cast<const char *>(&value), 4, data.end() - 4);
}

std::atomic<bool> isRunning(true);

/**
 * @brief Формирует новый вектор с тем же CRC32, добавляя в конец оригинального
 * строку injection и дополнительные 4 байта
 * @details При формировании нового вектора последние 4 байта не несут полезной
 * нагрузки и подбираются таким образом, чтобы CRC32 нового и оригинального
 * вектора совпадали
 * @param original оригинальный вектор
 * @param injection произвольная строка, которая будет добавлена после данных
 * оригинального вектора
 * @return новый вектор
 */
void hack(const std::vector<char> &original,
                       const std::string &injection, size_t start, size_t end, std::vector<char> &badData) {
                        
  const uint32_t originalCrc32 = crc32(original.data(), original.size());
  std::vector<char> result(original.size() + injection.size() + 4);
  auto it = std::copy(original.begin(), original.end(), result.begin());
  std::copy(injection.begin(), injection.end(), it);

    /*
    * Внимание: код ниже крайне не оптимален.
    * В качестве доп. задания устраните избыточные вычисления
    */

  auto resultCrc32 = crc32(result.data() + original.size(), injection.size(), ~originalCrc32);

  
  for (size_t i = start; i < end; ++i) {
    if (isRunning) {
    // Заменяем последние четыре байта на значение i
      replaceLastFourBytes(result, uint32_t(i));
    // Вычисляем CRC32 текущего вектора result
      auto currentCrc32 = crc32(result.data() + original.size() + injection.size(), 4, ~resultCrc32);

      if (currentCrc32 == originalCrc32) {
        std::cout << "Success\n";
        badData = result;
        isRunning = false;
        return;
      }
      // Отображаем прогресс
      // if (i % 1000 == 0) {
      //   std::cout << "progress: "
      //             << static_cast<double>(i) / static_cast<double>(end)
      //             << std::endl;
      // }
    }
    else return;
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Call with two args: " << argv[0]
              << " <input file> <output file>\n";
    return 1;
  }

  auto start_time = std::chrono::steady_clock::now();

  try {
    const std::vector<char> data = readFromFile(argv[1]);
    std::vector<char> badData;
    const size_t maxVal = std::numeric_limits<uint32_t>::max();
    // size_t threadsNumber = std::thread::hardware_concurrency();
    size_t threadsNumber = 4;
    std::vector<std::thread> threads;

    size_t chunk_size = maxVal / threadsNumber;
    for (size_t i = 0; i < threadsNumber; ++i) {
        size_t start = i * chunk_size;
        size_t end = (i == threadsNumber - 1) ? maxVal : (i + 1) * chunk_size;
        threads.emplace_back(hack, data, "He-he-he", start, end, std::ref(badData));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    writeToFile(argv[2], badData);

    auto end_time = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsed_seconds = end_time - start_time;

    std::cout << "Программа заверщилась за " << elapsed_seconds.count() << " секунд" << std::endl;

  } catch (std::exception &ex) {
    std::cerr << ex.what() << '\n';
    return 2;
  }
  return 0;
}
