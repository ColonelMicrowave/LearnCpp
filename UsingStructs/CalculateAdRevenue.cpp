#include <iostream>
#include <limits>
#include <string>

struct AdRevenue
{
	int adsWatched{};
	double clickRatePercent{};
	double averageEarningsPerClick{};
};

template <typename T>
T getValidatedInput(std::string_view prompt)
{
	T input{};
	while (true)
	{
		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please try again.\n";
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}

AdRevenue getAdRevenue()
{
	AdRevenue temp{};

	temp.adsWatched = getValidatedInput<int>("Enter the number of ads watched: ");
	temp.clickRatePercent = getValidatedInput<double>("Enter the click rate percentage: ");
	temp.averageEarningsPerClick = getValidatedInput<double>("Enter the average earnings per click: ");

	return temp;
}

void printAdRevenue(const AdRevenue& ad)
{
	std::cout << "Number of ads watched: " << ad.adsWatched << '\n';
	std::cout << "Click rate percentage: " << ad.clickRatePercent << '\n';
	std::cout << "Average earnings per click: " << ad.averageEarningsPerClick << '\n';
	std::cout << "Total earnings: " << (ad.adsWatched * (ad.clickRatePercent / 100) * ad.averageEarningsPerClick) << '\n';
}

int main()
{
	AdRevenue adRevenue{ getAdRevenue() };
	printAdRevenue(adRevenue);

	return 0;
}
