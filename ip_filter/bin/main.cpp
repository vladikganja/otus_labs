#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <any>
#include <fstream>
#include <filesystem>
#include <algorithm>

std::vector<std::string> split(
    const std::string& str,
    char d)
{
    std::vector<std::string> res;

    size_t start = 0;
    size_t stop = str.find_first_of(d);
    while (stop != std::string::npos) {
        res.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    res.push_back(str.substr(start));
    return res;
}

void formatIpOutput(
    const std::vector<std::vector<std::string>>& ip_pool)
{
    for (const auto& ip: ip_pool) {
        for (size_t i = 0; i < ip.size() - 1; i++) {
            std::cout << ip[i] << ".";
        }
        std::cout << ip.back() << "\n";
    }
    std::cout << std::endl;
}

auto filter(
    const std::vector<std::vector<std::string>>& ip_pool,
    int64_t first = -1,
    int64_t second = -1,
    int64_t third = -1,
    int64_t fourth = -1)
{
    auto matches = [&](const std::vector<std::string>& ip) -> bool {
        if ((first != -1 && std::stoll(ip[0]) != first) ||
            (second != -1 && std::stoll(ip[1]) != second) ||
            (third != -1 && std::stoll(ip[2]) != third) ||
            (fourth != -1 && std::stoll(ip[3]) != fourth))
        {
            return false;
        }
        return true;
    };

    std::vector<std::vector<std::string>> res;
    for (const auto& ip : ip_pool) {
        if (matches(ip)) {
            res.emplace_back(ip);
        }
    }
    return res;
}

auto filter_any(
    const std::vector<std::vector<std::string>>& ip_pool,
    int64_t value)
{
    auto matches = [&value](const std::vector<std::string>& ip) -> bool {
        for (const auto& part : ip) {
            if (std::stoll(part) == value) {
                return true;
            }
        }
        return false;
    };

    std::vector<std::vector<std::string>> res;
    for (const auto& ip : ip_pool) {
        if (matches(ip)) {
            res.emplace_back(ip);
        }
    }
    return res;
}

int main()
try {
    std::vector<std::vector<std::string>> ip_pool;

    for (std::string line; std::getline(std::cin, line);) {
        auto v = split(line, '\t');
        ip_pool.emplace_back(split(v.at(0), '.'));
    }

    std::sort(ip_pool.begin(), ip_pool.end(),
    [](const std::vector<std::string>& lhs, const std::vector<std::string>& rhs) {
        assert(lhs.size() == rhs.size());
        for (size_t i = 0; i < lhs.size(); i++) {
            auto intLhs = std::stoi(lhs[i]);
            auto intRhs = std::stoi(rhs[i]);
            if (intLhs != intRhs) {
                return intLhs > intRhs;
            }
        }
        return false;
    });

    formatIpOutput(ip_pool);

    formatIpOutput(filter(ip_pool, 1));

    formatIpOutput(filter(ip_pool, 46, 70));

    formatIpOutput(filter_any(ip_pool, 46));

    return EXIT_SUCCESS;
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}
