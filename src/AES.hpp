#pragma once

#include "Types.hpp"

#include <array>
#include <cstdint>

// Encryption constants (in bytes)
constexpr int IV = 16;
constexpr int Key = 32;

class AES {
public:
	static void Setup();
	static void Cleanup();
	
	static int Encrypt(bytes<Key> key, bytes<IV> iv, byte_t *plaintext, int plen, byte_t *ciphertext);
	static int Decrypt(bytes<Key> key, bytes<IV> iv, byte_t *ciphertext, int clen, byte_t *plaintext);
	
	static int GetCiphertextLength(int plen);
	static bytes<16> GenerateIV();
};
