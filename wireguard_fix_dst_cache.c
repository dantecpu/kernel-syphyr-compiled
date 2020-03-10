    net: Fix Wireguard compile error
    
    This function has been backported by the following commits:
    
    fixes: "ipv6: Add rt6_get_cookie() function"
    fixes: "ipv6: add rcu grace period before freeing fib6_node"

diff --git a/src/compat/dst_cache/dst_cache.c b/src/compat/dst_cache/dst_cache.c
index 7ec22f7..ca96234 100644
--- a/src/compat/dst_cache/dst_cache.c
+++ b/src/compat/dst_cache/dst_cache.c
@@ -15,7 +15,7 @@
 #include <net/route.h>
 #if IS_ENABLED(CONFIG_IPV6)
 #include <net/ip6_fib.h>
-#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 2, 0) && LINUX_VERSION_CODE >= KERNEL_VERSION(3, 17, 0)) || LINUX_VERSION_CODE < KERNEL_VERSION(3, 16, 50)
+#if 0
 static inline u32 rt6_get_cookie(const struct rt6_info *rt)
 {
        if ((unlikely(rt->dst.flags & DST_NOCACHE) && rt->dst.from))
