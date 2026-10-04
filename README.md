# Computer Security Laboratory Course

This repository contains my all lab task code for the Computer Security Laboratory Course. It includes C++ implementations of several classical and public-key cryptographic algorithms used during the lab exercises.

## Repository Contents

- [ecc_enc_dec.cpp](ecc_enc_dec.cpp) – ECC encryption and decryption
- [ecc_homomorphic.cpp](ecc_homomorphic.cpp) – ECC homomorphic property demonstration
- [elgamal_enc_dec.cpp](elgamal_enc_dec.cpp) – ElGamal encryption and decryption
- [elgamal_product.cpp](elgamal_product.cpp) – ElGamal product-based operation
- [elgamal_rerandomization.cpp](elgamal_rerandomization.cpp) – Ciphertext rerandomization
- [elgamal_signature.cpp](elgamal_signature.cpp) – ElGamal digital signature
- [rsa_enc_dec.cpp](rsa_enc_dec.cpp) – RSA encryption and decryption
- [rsa_product.cpp](rsa_product.cpp) – RSA product-based operation
- [rsa_signature.cpp](rsa_signature.cpp) – RSA signature implementation
- [vernam_cipher.cpp](vernam_cipher.cpp) – Vernam cipher implementation

## Theory and Procedure of Each Algorithm

### 1. RSA Encryption and Decryption
RSA is a public-key cryptosystem based on large prime numbers.

Procedure:
- Choose two large prime numbers p and q.
- Compute n = p × q and phi(n) = (p - 1)(q - 1).
- Select public exponent e with gcd(e, phi(n)) = 1.
- Compute private exponent d such that d × e ≡ 1 (mod phi(n)).
- Encryption: C = M^e mod n.
- Decryption: M = C^d mod n.

This provides confidentiality using a public key for encryption and a private key for decryption.

### 2. RSA Product Operation
This demonstrates mathematical properties of RSA under multiplication.

Procedure:
- Encrypt two messages separately using the same RSA public key.
- Multiply the ciphertexts together.
- The result corresponds to the product of the original messages after decryption under the right modular relation.

This shows how RSA can behave in a multiplicative setting and is useful for studying algebraic properties.

### 3. RSA Signature
RSA can also be used for digital signatures.

Procedure:
- Use the private key to sign a message hash.
- Signature = H(M)^d mod n.
- Verification uses the public key: H(M) = Signature^e mod n.

If the verification succeeds, the signature is valid and confirms the sender's identity.

### 4. ElGamal Encryption and Decryption
ElGamal is based on the discrete logarithm problem.

Procedure:
- Choose a prime p and a generator g.
- Select private key x and compute public key y = g^x mod p.
- Choose random k for each message.
- Compute c1 = g^k mod p.
- Compute c2 = M × y^k mod p.
- Ciphertext = (c1, c2).
- Decryption uses x: M = c2 × (c1^x)^(-1) mod p.

This is a probabilistic encryption scheme because each message can produce different ciphertexts with different random values.



### 5. ElGamal Product Operation
This focuses on multiplication of ElGamal ciphertexts or values in the group.

Procedure:
- Encrypt messages using ElGamal.
- Combine the encrypted values using modular multiplication.
- Decrypt the combined ciphertext to reveal the corresponding product or transformed value.

It helps understand how group operations affect encrypted data.

### 6. ElGamal Rerandomization
Rerandomization creates a new valid encryption of the same message without revealing the original plaintext.

Procedure:
- Start with an existing ElGamal ciphertext.
- Choose a new random value.
- Recompute the ciphertext using that random value while preserving the same message.

The result is a different-looking ciphertext but decrypts to the same original message.

### 7. ElGamal Signature
ElGamal signatures provide authenticity and integrity.

Procedure:
- Choose random secret k with gcd(k, p - 1) = 1.
- Compute r = g^k mod p.
- Compute s = k^(-1) × (H(M) - x × r) mod (p - 1).
- Signature is (r, s).
- Verification checks whether g^H(M) = y^r × r^s mod p.

If the equation holds, the message is accepted as authentic.

### 8. ECC Encryption and Decryption
ECC (Elliptic Curve Cryptography) uses points on an elliptic curve instead of large primes alone.

Procedure:
- Choose an elliptic curve and a base point G.
- Select private key d and compute public key Q = dG.
- To encrypt a message point P, choose random k.
- Compute C1 = kG and C2 = P + kQ.
- Decrypt using C2 - dC1 = P.

ECC provides strong security with smaller key sizes compared to RSA.

### 9. ECC Homomorphic Property
ECC also supports homomorphic behavior in additive form on elliptic curve points.

Procedure:
- Take two messages as points on the elliptic curve.
- Choose random scalars and generate encrypted ciphertext pairs.
- Add the ciphertexts together in the curve group.
- Decrypt the combined ciphertext using the private key.
- The result matches the sum of the original messages.

This demonstrates the additive homomorphic property of ECC-based encryption in a practical implementation.

### 10. Vernam Cipher
The Vernam cipher is a one-time pad cipher.

Procedure:
- Convert plaintext and key to the same length.
- XOR each plaintext bit with the corresponding key bit.
- Encryption and decryption use the same XOR operation.

This is perfectly secure only when the key is truly random, secret, and used only once.

## Compiler Requirements

```powershell
gcc --version
```

Output:

```text
gcc (Rev5, Built by MSYS2 project) 16.1.0
Copyright (C) 2026 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

This repository uses GCC/MSYS2 compiler support for `__int128` and `#define ll long long int`.



## Conclusion

This repository covers the core concepts of modern cryptography and classic cipher design, including public-key systems, digital signatures, homomorphic behavior, elliptic curve methods, and one-time pad encryption. These programs are useful for understanding how cryptographic algorithms work step by step in practice.

---

Pritom Banik <br>
10 Semtember 2026 <br>
CSE4116 : Computer Security Laboratory

