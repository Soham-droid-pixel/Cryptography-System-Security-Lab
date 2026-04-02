import hashlib
import time

# 1. Setup: Create 1KB file
file_name = "example_100mb.txt"
with open(file_name, "w") as f:
    f.write("A" * 1000)

def get_timing(algo, file_path):
    start = time.perf_counter()
    h = hashlib.new(algo)
    with open(file_path, "rb") as f:
        for chunk in iter(lambda: f.read(4096), b""):
            h.update(chunk)
    h.hexdigest()
    return time.perf_counter() - start

# 2. Compare Timings
md5_time = get_timing('md5', file_name)
sha1_time = get_timing('sha1', file_name)

print(f"--- Results ---")
print(f"MD5 Time:  {md5_time:.10f} seconds")
print(f"SHA-1 Time: {sha1_time:.10f} seconds")

# 3. Conclusion for your exam
if md5_time < sha1_time:
    diff = ((sha1_time - md5_time) / sha1_time) * 100
    print(f"\nConclusion: MD5 is faster by approx {diff:.2f}%")
else:
    diff = ((md5_time - sha1_time) / md5_time) * 100
    print(f"\nConclusion: SHA-1 is faster by approx {diff:.2f}%")