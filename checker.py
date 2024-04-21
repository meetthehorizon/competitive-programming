import os
import time
import string
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
        output = f.read()

    with open(expected_output_file, "r") as f:
        expected_output = f.read()

    return output == expected_output

def generate_test_case(input_file):
    with open(input_file, "w") as f:
        f.write("1\n")
        n = 100000
        single = random.randint(0, n)
        double = random.randint(0, (n - single) // 2)

        lst = []
        for _ in range(single):
            lst += [(1, 1)]
        
        for _ in range(double):
            lst += [(1, 2)]

        f.write(f"{n} {single + double}\n")
        for asdas in lst:
            f.write(f"{asdas[0]} {asdas[1]} ")

if __name__ == "__main__":
    code = compile("code.cpp")
    brute = compile("brute.cpp")

    random.seed(time.time())

    for i in range(100):
        generate_test_case(f"inputf.in")

        run(brute, "inputf.in", "ex_outputf.in")
        run(code, "inputf.in", "outputf.in")

        if not checker("outputf.in", "ex_outputf.in"):
            print("Test case failed")
            os.remove(code)
            os.remove(brute)
            exit(0)

    os.remove(code)
    os.remove(brute)
    print("All test cases passed")
