USE class;-- �л���Ŀ�����ݿ�

-- ������¼�˻�����������
CREATE LOGIN u1 WITH PASSWORD = '123456'
-- ����¼�˻����û�����
CREATE USER  u1 FOR LOGIN u1;
-- �����û���Ĭ��ģʽ
ALTER USER u1 WITH DEFAULT_SCHEMA = dbo;
-- �����û��Ա��Ȩ��
GRANT SELECT, INSERT, UPDATE, DELETE ON YourTableName TO u1; 

drop login u1;

drop login zy079798;

