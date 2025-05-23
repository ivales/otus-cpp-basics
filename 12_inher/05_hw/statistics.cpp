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
	Mean() : m_count{0}, m_mean{0}  {
	}

	void update(double next) override {
		
		m_mean += next;
		m_count++;
	}

	double eval() const override {
		if (m_count == 0) throw std::domain_error("Division by zero!");
		return m_mean/m_count;
	}

	const char * name() const override {
		return "mean";
	}

private:
	int m_count;
	double m_mean;
};

class Std : public IStatistics {
public:
	Std() : m_count{0}, m_mean{0}, m_std{0}, m_numbers{} {
	}

	void update(double next) override {
		
		m_numbers.push_back(next);
		m_mean += next;
		m_count++;
	}

	double eval() const override {
		double disp = 0;
		if (m_count == 0 || m_count == 1) throw std::domain_error("Division by zero!");
		double mean = m_mean/m_count;
		for (double number:m_numbers) {disp += pow(number - mean, 2);}
		return sqrt(disp/m_count-1);
	}

	const char * name() const override {
		return "std";
	}

private:
	int m_count;
	double m_mean, m_std;	
	std::vector<double> m_numbers;
};

class Procentile : public IStatistics {
	public:
		Procentile(double d) : m_numbers{}, m_percentile{d} {};
		
	void update(double next) override {
		m_numbers.push_back(next);
		std::sort(begin(m_numbers), end(m_numbers));
	}

	double eval() const override {
		return m_numbers[static_cast<int>(m_percentile*m_numbers.size()/100)];
	}
	private:
		std::vector<double> m_numbers;
		double m_percentile;
};

class P90 : public Procentile {
public:
	P90() : Procentile(90) {}

	const char * name() const override {
		return "p90";
	}

};

class P95 : public Procentile {
	public:
		P95() : Procentile(95) {}

	const char * name() const override {
		return "p95";
	}

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