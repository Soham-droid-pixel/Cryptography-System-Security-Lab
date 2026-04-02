import hashlib
import time

# 1. Setup: Create 1KB file 
# (Note: I kept the 1000 chars to keep it fast for your test)
file_name = "example_100mb.txt"
with open(file_name, "w") as f:
    f.write("A" * 1000)

def get_timing_and_hash(algo, file_path):
    start = time.perf_counter()
    h = hashlib.new(algo)
    with open(file_path, "rb") as f:
        # Reading in chunks is best practice for exams!
        for chunk in iter(lambda: f.read(4096), b""):
            h.update(chunk)
    
    digest = h.hexdigest() # This is the "encrypted-looking" text
    duration = time.perf_counter() - start
    return duration, digest

# 2. Run Benchmarks
md5_time, md5_hash = get_timing_and_hash('md5', file_name)
sha1_time, sha1_hash = get_timing_and_hash('sha1', file_name)

# 3. Display Results
print(f"{'Algorithm':<10} | {'Time (Seconds)':<15} | {'Hash Digest'}")
print("-" * 70)
print(f"{'MD5':<10} | {md5_time:.10f} | {md5_hash}")
print(f"{'SHA-1':<10} | {sha1_time:.10f} | {sha1_hash}")

# 4. Conclusion
if md5_time < sha1_time:
    diff = ((sha1_time - md5_time) / sha1_time) * 100
    print(f"\nConclusion: MD5 is faster by {diff:.2f}%")
else:
    diff = ((md5_time - sha1_time) / md5_time) * 100
    print(f"\nConclusion: SHA-1 is faster by {diff:.2f}%")