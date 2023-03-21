# 二分法

## 边界的选择

1. 左闭右开 [0,n)      (规范中较为常用)
2. 左闭右闭 [0,n-1]

### 左闭右开

核心：right是取不到的；每一次进入while都要确保范围可以变小

when nums[mid] < target:
 此时需要left右移
 首先我们知道mid必不为解，即mid需要被抛弃，
 若left=mid,则在下一次while中还可以取到，如果left本就等于mid，则区间不会收缩，就会出现问题

 因此，需要
 left = mid +1

when nums[mid] > target:
 此时需要right右移
 使用right = mid，可知mid是取不到的，即被抛弃，除非left==right，然而这种情况下根本不会进while循环

 使用right = mid-1，会导致mid-1也被抛弃，即还没有检验mid-1就抛弃了它。

 因此，需要
 right = mid

取中点的方法：
 推荐 mid = left +(right-left)/2
 可以避免溢出
