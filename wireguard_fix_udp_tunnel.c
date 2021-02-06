    net: Fix error with ip_select_ident
    
    Fixes: "ipv4: hash net ptr into fragmentation bucket selection"
    Fixes: "ipv4: ip_tunnel: use net namespace from rtable not socket"

diff --git a/src/compat/udp_tunnel/udp_tunnel.c b/src/compat/udp_tunnel/udp_tunnel.c
index ae43566..7c85d0e 100644
--- a/src/compat/udp_tunnel/udp_tunnel.c
+++ b/src/compat/udp_tunnel/udp_tunnel.c
@@ -166,7 +166,7 @@ static void __compat_iptunnel_xmit(struct rtable *rt, struct sk_buff *skb,
 #if LINUX_VERSION_CODE < KERNEL_VERSION(3, 10, 53)
        __ip_select_ident(iph, &rt->dst, (skb_shinfo(skb)->gso_segs ?: 1) - 1);
 #else
-       __ip_select_ident(iph, skb_shinfo(skb)->gso_segs ?: 1);
+       __ip_select_ident(dev_net(rt->dst.dev), iph, skb_shinfo(skb)->gso_segs ?: 1);
 #endif
 
        iptunnel_xmit(skb, skb->dev);
