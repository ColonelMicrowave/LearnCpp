#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
    [[maybe_unused]] constexpr std::uint8_t option_favourited{ 0x04 };
    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags{ option_favourited };

    myArticleFlags |= option_viewed; // 1. Set the article as viewed
    std::cout << ((myArticleFlags & option_deleted) ? "Article was deleted\n" : "Article was not deleted\n"); // 2. Check if the article was deleted
    myArticleFlags &= static_cast<std::uint8_t>(~option_favourited); // 3. Remove the article from favourites

    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    return 0;
}
