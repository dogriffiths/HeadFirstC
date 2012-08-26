    <bytes read> = recv(<descriptor>, <buffer>, <bytes to read>, 0);
 |---+---+---+---+---+---+---+---+---+---+---+---+----+----|
 | W | h | o | ' | s |   | t | h | e | r | e | ? | \r | \n |
 |---+---+---+---+---+---+---+---+---+---+---+---+----+----|
 int read_in(int d, char* buf, int buflen) {
   int count = recv(d, buf, buflen, 0);
   if (count > 1)
     buf[count - 2] = '\0';
   else
     buf[0] = '\0';
   return count;
 }
 char buf[255];
 if (read_in(d, buf, sizeof(buf)) == -1) {
   /* Handle the error */
 }
char* s = buf;
   int slen = len;
   int c = recv(socket, s, slen, 0);
   while ((c > 0) && (s[c-1] != '\n')) {
     s++; slen -= c;
     c = recv(socket, s, slen, 0);
   }
   if (c < 0) 
     return c;
   else if (c == 0)
     buf[0] = '\0';
   else
     s[c-1]='\0';
   return slen - len;
 }
