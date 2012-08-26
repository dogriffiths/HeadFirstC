  <s>bind (listener_d, (struct sockaddr *) &name, sizeof (name));</s>
  if (bind (listener_d, (struct sockaddr *) &name, sizeof (name)) == -1)
    error("Can't bind the port");
 $ ./advice_server
 Waiting for connection
 ^C
 $ ./advice_server
 Can't bind the port: Address already in use
 $
  int reuse = 1;
  if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
    error("Can't set the reuse option on the socket");
