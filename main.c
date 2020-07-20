#include <stdio.h>
#include <Windows.h>

typedef BOOL (WINAPI *DnsFlushResolverCacheFuncPtr)();

int main() {
    HMODULE dnsapi = LoadLibrary("dnsapi.dll");
    if (dnsapi == NULL) {
        printf("Failed loading module: %d\n", GetLastError());
        return -1;
    }
    DnsFlushResolverCacheFuncPtr DnsFlushResolverCache = (DnsFlushResolverCacheFuncPtr)GetProcAddress(dnsapi, "DnsFlushResolverCache");
    if (DnsFlushResolverCache == NULL) {
        printf("Failed loading function: %d\n", GetLastError());
        FreeLibrary(dnsapi);
        return -2;
    }
    BOOL result = DnsFlushResolverCache();
    if (result) {
        printf("DnsFlushResolverCache succeeded\n");
    } else {
        printf("DnsFlushResolverCache succeeded: %d\n", GetLastError());
    }
    FreeLibrary(dnsapi);
    return 0;
}
