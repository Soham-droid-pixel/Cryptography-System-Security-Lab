# Topic 13: RSA Digital Signature Algorithm

# 1. SETUP: Standard RSA Keys
n = 3233  # The modulus (p * q)
e = 17    # Public Key (used for verification)
d = 2753  # Private Key (used for signing)

# 2. SENDER SIDE: Signing the message
def sign_message(message, private_key, modulus):
    signature = []
    for char in message:
        # Convert character to ASCII number
        ascii_val = ord(char)
        # Apply RSA formula: (Message ^ d) % n
        signed_val = pow(ascii_val, private_key, modulus)
        signature.append(signed_val)
    return signature

# 3. RECEIVER SIDE: Verifying the signature
def verify_signature(original_msg, signature, public_key, modulus):
    decrypted_message = ""
    for num in signature:
        # Apply RSA formula: (Signature ^ e) % n
        decrypted_ascii = pow(num, public_key, modulus)
        # Convert ASCII number back to character
        decrypted_message += chr(decrypted_ascii)
    
    print("Decrypted Message found:", decrypted_message)
    # Check if the decrypted text matches the original message
    if decrypted_message == original_msg:
        return True
    else:
        return False

# --- MAIN EXECUTION ---
my_msg = "HELLO"

# Step A: Sender signs the message
sig = sign_message(my_msg, d, n)
print("Original Message:", my_msg)
print("Digital Signature (List of numbers):", sig)

print("-" * 40)

# Step B: Receiver verifies the message
is_valid = verify_signature(my_msg, sig, e, n)

if is_valid:
    print("RESULT: Signature is VALID. Message is authentic.")
else:
    print("RESULT: Signature is INVALID!")