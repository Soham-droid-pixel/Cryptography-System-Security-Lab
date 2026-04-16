import hashlib
import os

# --- CONFIGURATION ---
PEPPER = "FCRCE_SECRET_2026"  # Static secret stored on the server
DATABASE = {}

def get_hash(data):
    """Utility to generate a SHA-256 hex digest."""
    return hashlib.sha256(data.encode()).hexdigest()

def simulate_step(title, success_condition):
    status = "SUCCESS ✅" if success_condition else "FAILED ❌"
    print(f"[{title}] Result: {status}")

# --- MAIN LOGIC ---

username = "Soham"
password = "ExamPassword123"
wrong_password = "WrongPassword456"

print(f"--- STARTING LOGIN SIMULATION FOR: {username} ---\n")

# ---------------------------------------------------------
# METHOD 1: Plain Hashing (No Salt, No Pepper)
# ---------------------------------------------------------
stored_hash_v1 = get_hash(password)

# Step 1: Success
simulate_step("Method 1: Plain Hash - Correct PW", get_hash(password) == stored_hash_v1)
# Step 2: Fail
simulate_step("Method 1: Plain Hash - Wrong PW", get_hash(wrong_password) == stored_hash_v1)

print("-" * 30)

# ---------------------------------------------------------
# METHOD 2: Password + Salt
# ---------------------------------------------------------
salt_v2 = os.urandom(16).hex()
stored_hash_v2 = get_hash(password + salt_v2)

# Step 3: Success
simulate_step("Method 2: Salted Hash - Correct PW", get_hash(password + salt_v2) == stored_hash_v2)
# Step 4: Fail
simulate_step("Method 2: Salted Hash - Wrong PW", get_hash(wrong_password) + salt_v2 == stored_hash_v2)

print("-" * 30)

# ---------------------------------------------------------
# METHOD 3: Password + Salt + Pepper
# ---------------------------------------------------------
salt_v3 = os.urandom(16).hex()
# Formula: Hash(Password + Salt + Pepper)
stored_hash_v3 = get_hash(password + salt_v3 + PEPPER)

# Step 5: Success
simulate_step("Method 3: Salt & Pepper - Correct PW", get_hash(password + salt_v3 + PEPPER) == stored_hash_v3)
# Step 6: Fail
# Scenario: Correct Password but missing/wrong Pepper
simulate_step("Method 3: Salt & Pepper - Wrong Pepper", get_hash(password + salt_v3 + "WRONG_PEPPER") == stored_hash_v3)

print("\n--- SIMULATION COMPLETE ---")