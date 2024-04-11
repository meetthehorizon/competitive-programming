import os
import shutil
import random
import subprocess

def compile(code_path):
    executable_name = os.path.splitext(code_path)[0]
    compile_command = f"g++ {code_path} -o {executable_name}"
    compile_process = subprocess.run(
        compile_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )

    if compile_process.returncode != 0:
        print(
            f"Compilation failed with error:\n{compile_process.stderr.decode('utf-8')}"
        )
        return
    
    return executable_name

def run(executable_name, input_path, output_path):
    run_command = f"./{executable_name}<{input_path}>{output_path}"
    run_process = subprocess.run(
        run_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )

    if run_process.returncode != 0:
        print(
            f"Program execution failed with error:\n{run_process.stderr.decode('utf-8')}"
        )
        return


def checker(output_file, expected_output_file):
    with open(output_file, "r") as f:
        output = f.readlines()
    with open(expected_output_file, "r") as f:
        expected_output = f.readlines()

    if output == expected_output:
        return True
    else:
        return False


def generate_test_case(input_file):
    t = random.randint(3, 10)
    
    with open(input_file, "w") as f:
        f.write(f"{t}\n")

        for _ in range(t):
            a = random.randint(1, 10)
            b = random.randint(1, 10)

            f.write(f"{a} {b}\n")


if __name__ == "__main__":
    code = compile("code.cpp")
    brute = compile("brute.cpp")

    for i in range(100):
        generate_test_case(f"inputf.in")

        run(brute, "inputf.in", "outputf.in")
        run(code, "inputf.in", "ex_output.in")

        if not checker("outputf.in", "ex_output.in"):
            print("Test case failed")
            os.remove(code)
            os.remove(brute)
            exit(0)

    os.remove(code)
    os.remove(brute)
    print("All test cases passed")
