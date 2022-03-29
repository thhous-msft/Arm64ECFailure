# Arm64EC failure

Trying to call a function taking more then 3 arguments across a DLL boundary between architectures crashes with a completely garbage stack trace.

It does not matter if caller is Arm64EC and callee X64, or vise versa. Both instances fail.

To test

1. Run build.ps1
2. Copy ectest.exe from buildarm/Debug to test computer
3. Copy ectestdll.dll from buildx64/Debug to test computer
4. Run ectest.exe. Program will will print that it can call 1 and 2 arg functions, but will never printed that it called the 3 arg function, and crashes. Debugging shows the thread stack is completely destroyed.
