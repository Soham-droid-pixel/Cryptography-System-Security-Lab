import hashlib, os

# 1. Setup
PEPPER = "MY_SECRET_CODE"  # Stored in code, NOT database
salt = os.urandom(16).hex() # Unique per user, stored in DB
password = "Admin123"

# 2. Registration (Hashing)
# Formula: Hash(Password + Salt + Pepper)
combined = password + salt + PEPPER
stored_hash = hashlib.sha256(combined.encode()).hexdigest()

# 3. Login (Verification)
input_pw = "Admin123"
check_combined = input_pw + salt + PEPPER
input_hash = hashlib.sha256(check_combined.encode()).hexdigest()

if input_hash == stored_hash:
    print("Success: Logged in!")
else:
    print("Failed: Incorrect password.")