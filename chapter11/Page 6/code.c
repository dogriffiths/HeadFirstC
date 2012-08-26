  char* msg = "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ";
  if (send(connect_d, msg, strlen(msg), 0) == -1)
    error("send");
