# minitalk
One way chat app using unix [signals](https://www.gnu.org/software/libc/manual/html_node/Miscellaneous-Signals.html).


![App screenshot](https://github.com/akinori-s/minitalk/blob/main/docs/minitalk.gif?raw=true)

## How to Run

1. Clone the repository and compile the program.
```bash
git clone https://github.com/akinori-s/minitalk.git
cd minitalk
make
```

2. Run the server side of the application and copy the prcess ID.

```bash
./server
```

3. Open another terminal and send messages with the server's process ID.
```bash
./client [PID] "Hello world!"
```
