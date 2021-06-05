import subprocess

for i in range(10000):
    command_result = subprocess.run(['rasm2', '-a', 'arm.gnu', '-b', '16', '-c', 'm4',  '-d', '1234'], capture_output=True)

print(command_result.stdout)
