#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
};

class Mean : public IStatistics {
public:
	Mean() : m_mean{0} {
	}

	void update(double next) override {
		
		m_mean += next;
		count++;
	}

	double eval() const override {
		return m_mean/count;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double m_mean;
	int count = 0;
};

class Std : public IStatistics {
public:
	Std() : m_std{0} {
	}

	void update(double next) override {
		
		numbers.push_back(next);
		m_mean += next;
		count++;
	}

	double eval() const override {
		double disp = 0;
		double mean = m_mean/count;
		for (double number:numbers) {disp += pow(number - mean, 2);}
		return sqrt(disp/count-1);
	}

	const char * name() const override {
		return "std";
	}

private:
	std::vector<double> numbers;
	double m_mean, m_std;
	int count = 0;
};

class P90 : public IStatistics {
public:
	P90() : m_proc{90} {}

	void update(double next) override {
		
		numbers.push_back(next);
		std::sort(begin(numbers), end(numbers));
	}

	double eval() const override {
		return numbers[static_cast<int>(m_proc*numbers.size()/100)];
	}

	const char * name() const override {
		return "p90";
	}

private:
	std::vector<double> numbers;
	double m_proc;
};

class P95 : public P90 {
public:
	P95() : m_proc{95} {

	}

	const char * name() const override {
		return "p95";
	}

private:
	std::vector<double> numbers;
	double m_proc;

};


int main() {

	const size_t statistics_count = 6;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};
	statistics[4] = new P90{};
	statistics[5] = new P95{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}