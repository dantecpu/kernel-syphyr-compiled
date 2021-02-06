Fixes: udp: Generic functions to set checksum
---
 src/compat/udp_tunnel/udp_tunnel.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/src/compat/udp_tunnel/udp_tunnel.c b/src/compat/udp_tunnel/udp_tunnel.c
index 3319101..3f9bb88 100644
--- a/src/compat/udp_tunnel/udp_tunnel.c
+++ b/src/compat/udp_tunnel/udp_tunnel.c
@@ -89,7 +89,7 @@ void setup_udp_tunnel_sock(struct net *net, struct socket *sock,
 	*(void **)&sock->sk->sk_data_ready = (void *)__compat_sk_data_ready;
 }
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 16, 0)
+#if 0
 static inline __sum16 udp_v4_check(int len, __be32 saddr,
 				   __be32 daddr, __wsum base)
 {
@@ -307,7 +307,7 @@ error:
 	return err;
 }
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 16, 0)
+#if 0
 static inline __sum16 udp_v6_check(int len,
 		const struct in6_addr *saddr,
 		const struct in6_addr *daddr,
-- 
2.17.1
