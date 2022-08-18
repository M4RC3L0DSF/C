#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv){
    
    int i;
    struct hostent *he;
    struct in_addr **addr_list;

    if((he = gethost(argv[1])) == NULL){
        herror("gethost");
        return 2;
        }
        printf("\n[-] Official name is: %s\n", he->h_name);
        printf("[+] IP address: \n\n");
        addr_list = (struct in_addr **)he->h_addr_list;

        for(i = 0; addr_list[i] !=NULL; i++) {
            printf("\t\t%s \n", inet_ntoa(*addr_list[i]));
        }
    print("\n")
    return 0;
}