Fix compile error for sk_no_check

This has been backported to 3.10

Fixes: net: Split sk_no_check into sk_no_check_{rx,tx}
---
 src/compat/udp_tunnel/udp_tunnel.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/src/compat/udp_tunnel/udp_tunnel.c b/src/compat/udp_tunnel/udp_tunnel.c
index 26f6716..3319101 100644
--- a/src/compat/udp_tunnel/udp_tunnel.c
+++ b/src/compat/udp_tunnel/udp_tunnel.c
@@ -60,7 +60,7 @@ int udp_sock_create4(struct net *net, struct udp_port_cfg *cfg,
 			goto error;
 	}
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 16, 0)
+#if 0
 	sock->sk->sk_no_check = !cfg->use_udp_checksums;
 #else
 	sock->sk->sk_no_check_tx = !cfg->use_udp_checksums;
@@ -288,7 +288,7 @@ int udp_sock_create6(struct net *net, struct udp_port_cfg *cfg,
 	if (err < 0)
 		goto error;
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 16, 0)
+#if 0
 	sock->sk->sk_no_check = !cfg->use_udp_checksums;
 #else
 	udp_set_no_check6_tx(sock->sk, !cfg->use_udp6_tx_checksums);
-- 
2.17.1
