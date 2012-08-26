  if (listen(listener_d, 10) == -1)
    error("Can't listen");
  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof client_addr;
  int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
  if (connect_d == -1)
    error("Can't open secondary socket");
