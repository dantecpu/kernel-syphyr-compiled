This has been backported to 3.10 kernel
Fixes: net: rename local_df to ignore_df
---
 src/compat/compat.h | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/src/compat/compat.h b/src/compat/compat.h
index edc0502..fd37b19 100644
--- a/src/compat/compat.h
+++ b/src/compat/compat.h
@@ -787,7 +787,7 @@ struct __kernel_timespec {
 #define skb_probe_transport_header(a) skb_probe_transport_header(a, 0)
 #endif
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 16, 0) && !defined(ISRHEL7)
+#if 0
 #define ignore_df local_df
 #endif
 
-- 
2.17.1
