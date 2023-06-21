USE class;-- 切换到目标数据库

-- 创建登录账户并设置密码
CREATE LOGIN u1 WITH PASSWORD = '123456'
-- 将登录账户与用户关联
CREATE USER  u1 FOR LOGIN u1;
-- 设置用户的默认模式
ALTER USER u1 WITH DEFAULT_SCHEMA = dbo;
-- 授予用户对表的权限
GRANT SELECT, INSERT, UPDATE, DELETE ON YourTableName TO u1; 

drop login u1;

drop login zy079798;

