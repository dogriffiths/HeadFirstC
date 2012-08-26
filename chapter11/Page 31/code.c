 int say(int socket, char* s)
 {
   int result = send(socket, s, strlen(s), 0);
   if (result == -1)
     fprintf(stderr, "%s: %s\n", "Error talking to the server", strerror(errno));
   return result;
 }
 
 int main(int argc, char* argv[])
 {
   int d_sock;
   d_sock = open_socket("en.wikipedia.org", "80");
   char buf[255];
   sprintf(buf, "GET /wiki/%s http/1.1\r\n", argv[1]);
   say(d_sock, buf);
   say(d_sock, "Host: en.wikipedia.org\r\n\r\n");
   char rec[256];
   int bytesRcvd = recv(d_sock, rec, 255, 0);
   while (bytesRcvd) {
     if (bytesRcvd == -1)
       error("Can't read from server");
     rec[bytesRcvd] = '\0';
     printf("%s", rec);
     bytesRcvd = recv(d_sock, rec, 255, 0);
   }
   close(d_sock);
   return 0;
 }
 "Host: en.wikipedia.org\r\n"
 "\r\n"
