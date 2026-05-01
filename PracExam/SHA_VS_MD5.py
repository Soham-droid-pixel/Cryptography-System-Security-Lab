import hashlib, time

# 1. Setup: 1kB of data (1024 bytes)
data = b"A" * 1024 

# 2. Benchmark MD5
start = time.perf_counter()
md5_hash = hashlib.md5(data).hexdigest()
md5_time = time.perf_counter() - start

# 3. Benchmark SHA-1
start = time.perf_counter()
sha1_hash = hashlib.sha1(data).hexdigest()
sha1_time = time.perf_counter() - start

# 4. Output
print(f"MD5 Time:  {md5_time:.10f} s | Hash: {md5_hash}")
print(f"SHA1 Time: {sha1_time:.10f} s | Hash: {sha1_hash}")
"""import hashlib, time, os

# --- STEP 1: CREATE THE FILE (IF IT DOESN'T EXIST) ---
file_path = "sample.txt"
with open(file_path, "w") as f:
    f.write("A" * 1024) # Creates a file with exactly 1024 bytes (1kB)

# --- STEP 2: READ DATA FOR HASHING ---
with open(file_path, "rb") as f:
    file_data = f.read()

# --- STEP 3: BENCHMARK MD5 ---
start_md5 = time.perf_counter()
md5_result = hashlib.md5(file_data).hexdigest()
md5_time = time.perf_counter() - start_md5

# --- STEP 4: BENCHMARK SHA-1 ---
start_sha1 = time.perf_counter()
sha1_result = hashlib.sha1(file_data).hexdigest()
sha1_time = time.perf_counter() - start_sha1

# --- STEP 5: OUTPUT ---
print(f"{'Algorithm':<10} | {'Time (Seconds)':<15} | {'Hash Digest'}")
print("-" * 75)
print(f"{'MD5':<10} | {md5_time:.10f} | {md5_result}")
print(f"{'SHA-1':<10} | {sha1_time:.10f} | {sha1_result}")"""