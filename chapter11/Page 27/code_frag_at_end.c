 |------------------+-----------------|
 | Domain name      |         Address |
 |------------------+-----------------|
 | en.wikipedia.org |  91.198.174.225 |
 | www.oreilly.com  | 208.201.239.100 |
 | www.oreilly.com  | 208.201.239.101 |
 | ...              |             ... |
 |------------------+-----------------|
  #include <netdb.h>
  ...
  struct addrinfo *res;
  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = PF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  getaddrinfo("www.oreilly.com", "80", &hints, &res);
  int s = socket(res->ai_family, res->ai_socktype,
                       res->ai_protocol);
  connect(s, res->ai_addr, res->ai_addrlen);
  freeaddrinfo(res);
