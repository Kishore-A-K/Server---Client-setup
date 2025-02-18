This project demonstrates a client-server model using fork() where multiple clients send numerical data to a server, which processes it and returns the result. 
The server and clients communicate using pipes, a form of Inter-Process Communication (IPC) in Linux. 
Each client is created as a child process using fork(), allowing parallel execution. 
The clients prompt the user for input, send two numbers through the pipe, and exit after writing the data.

The server waits for all client processes to complete, then reads the numbers from the pipe, computes the sum, and displays the result. 
This setup efficiently handles multiple clients without the need for complex multi-threading or network-based communication. 
The use of blocking wait calls (wait()) ensures proper synchronization between parent and child processes, preventing data loss or race conditions.
