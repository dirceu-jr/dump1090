import subprocess
import os
import sys

def run_test():
    # Use the test binary if it exists, otherwise fallback to dump1090 (if compiled for test)
    binary = "./dump1090_test"
    if not os.path.exists(binary):
        binary = "./dump1090"

    print(f"Testing binary: {binary}")
    cmd = [binary, "--ifile", "testfiles/modes1.bin"]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, check=True)
        output = result.stdout
    except subprocess.CalledProcessError as e:
        print(f"Error running {binary}: {e}")
        return False

    expected_output_file = "expected_output.txt"
    if not os.path.exists(expected_output_file):
        print(f"Expected output file {expected_output_file} not found.")
        return False

    with open(expected_output_file, "r") as f:
        expected_output = f.read()

    # Normalize output (remove potential timing differences or dynamic data if any)
    # For now, we assume exact match is required as the input file is static.
    # However, whitespace might vary slightly or line endings.

    if output.strip() == expected_output.strip():
        print("Test passed!")
        return True
    else:
        print("Test failed!")
        # print("Expected output:")
        # print(expected_output)
        # print("-" * 20)
        # print("Actual output:")
        # print(output)
        return False

if __name__ == "__main__":
    if run_test():
        sys.exit(0)
    else:
        sys.exit(1)
