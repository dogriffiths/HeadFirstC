 close(connect_d);
 close(listener_d);
 Q: If I create a new process for each client, what happens if hundreds of clients connect? Will my machine create hundreds of processes?
 A: Yes. If you think your server will get a lot of clients, you need to control how many processes you create. The child can signal you when it's finished with a client and you can use that to maintain a count of current child processes.
