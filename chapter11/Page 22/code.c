  for(;;) {
    int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, 
                           &address_size);
    if (connect_d == -1)
      error("Can't open secondary socket");
    if (!fork()) {
      close(listener_d);
      if (say(connect_d, 
              "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ") 
          != -1) {
        read_in(connect_d, buf, sizeof(buf));
        if (strncasecmp("Who's there?", buf, 12))
          say(connect_d, "You should say 'Who's there?'!");
        else {
          if (say(connect_d, "Oscar\r\n> ") != -1) {
            read_in(connect_d, buf, sizeof(buf));
            if (strncasecmp("Oscar who?", buf, 10))
              say(connect_d, "You should say 'Oscar who?'!\r\n");
            else
              say(connect_d, "Oscar silly question, you get a silly answer\r\n");
          }
        }
      }
      close(connect_d);
      exit(0);
    }
    close(connect_d);
  }
