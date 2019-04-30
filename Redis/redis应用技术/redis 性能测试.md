## Redis 性能测试
Redis 性能测试是通过同时执行多个命令实现的。

## 语法
redis 性能测试的基本命令如下：

redis-benchmark [option] [option value]
注意：该命令是在 redis 的目录下执行的，而不是 redis 客户端的内部指令。

## 实例
以下实例同时执行 10000 个请求来检测性能：

$ redis-benchmark -n 10000  -q

## 实例
以下实例我们使用了多个参数来测试 redis 性能：

$ redis-benchmark -h 127.0.0.1 -p 6379 -t set,lpush -n 10000 -q

SET: 146198.83 requests per second
LPUSH: 145560.41 requests per second
以上实例中主机为 127.0.0.1，端口号为 6379，执行的命令为 set,lpush，请求数为 10000，通过 -q 参数让结果只显示每秒执行的请求数。
