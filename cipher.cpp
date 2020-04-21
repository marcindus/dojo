#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <utility>

const std::pair<int, int> allowedChars{32,127};

std::string encrypt(std::string message, const std::vector<int>& key) {
   std::transform(message.begin(), message.end(), message.begin(),
                   [=](unsigned char c) { return key[static_cast<int>(c)-allowedChars.first]; });
    return message;
}

std::string decrypt(std::string message, std::vector<int> key) {
    std::transform(message.begin(), message.end(), message.begin(),
                   [=](unsigned char c) {
                        return std::distance(key.begin(), std::find(key.begin(), key.end(), static_cast<int>(c))) + allowedChars.first;
                   });
    return message;
}

std::vector<int> generateKey() {
    std::vector<int> key(allowedChars.second-allowedChars.first);
    std::generate(key.begin(), key.end(), [n = allowedChars.first] () mutable { return n++; });
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(key.begin(), key.end(),  std::default_random_engine(seed));
    return key;
}


int main() {
    // Feel free change below code if needed.
    std::string message = "Hello, Coders School!";
    auto key = generateKey();
    auto cypher = encrypt(message, key);
    auto result = decrypt(cypher, key);
    std::cout << "Message: " << message << '\n';
    std::cout << "Cypher: " << cypher << '\n';
    std::cout << "Result: " << result << '\n';

    assert(message == result);
    return 0;
}

