-- CREATE DATABASE GradeDB;
-- CREATE TABLE STUDENT (
--     SID CHAR(13) NOT NULL,
--     SName VARCHAR(10) NOT NULL,
--     Age INTEGER NOT NULL,
--     Sex CHAR(2) NULL,
--     CONSTRAINT SID_PK PRIMARY KEY(SID)
-- );
-- CREATE TABLE COURSE (
--     CID CHAR(13) NOT NULL,
--     CName VARCHAR(10) NOT NULL,
--     Teacher VARCHAR(10) NOT NULL,
--     CONSTRAINT CID_PK PRIMARY KEY(CID)
-- );
-- CREATE TABLE GRADE (
--     SID CHAR(13) NOT NULL,
--     CID CHAR(13) NOT NULL,
--     Score INTEGER NULL,
--     Note TEXT NULL,
--     CONSTRAINT GRADE_PK PRIMARY KEY(SID, CID)
-- );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410001',
--         '刘夏花',
--         '20',
--         '女'
--     );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410002',
--         '金森风',
--         '22',
--         '男'
--     );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410003',
--         '丽莎',
--         '19',
--         '女'
--     );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410004',
--         '孟洱海',
--         '20',
--         '男'
--     );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410005',
--         '程君',
--         '20',
--         '男'
--     );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410006',
--         '何方帝',
--         '22',
--         '男'
--     );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410007',
--         '宋都素',
--         '20',
--         '女'
--     );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410008',
--         '苏娥',
--         '21',
--         '女'
--     );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410009',
--         '银烨',
--         '20',
--         '男'
--     );
-- INSERT INTO STUDENT
-- VALUES(
--         '2021042410010',
--         '童瑟余',
--         '23',
--         '男'
--     );
-- INSERT INTO COURSE
-- VALUES(
--         '2021042420001',
--         '数据库原理及应用',
--         '任永盛'
--     );
-- INSERT INTO COURSE
-- VALUES(
--         '2021042420002',
--         '数据结构与算法',
--         '施同恩'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410001',
--         '2021042420001',
--         '20',
--         '女'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410002',
--         '2021042420001',
--         '22',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410003',
--         '2021042420001',
--         '19',
--         '女'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410004',
--         '2021042420001',
--         '20',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410005',
--         '2021042420001',
--         '20',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410006',
--         '2021042420001',
--         '22',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410007',
--         '2021042420001',
--         '20',
--         '女'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410008',
--         '2021042420001',
--         '21',
--         '女'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410009',
--         '2021042420001',
--         '20',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410010',
--         '2021042420001',
--         '23',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410001',
--         '2021042420002',
--         '20',
--         '女'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410002',
--         '2021042420002',
--         '22',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410003',
--         '2021042420002',
--         '19',
--         '女'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410004',
--         '2021042420002',
--         '20',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410005',
--         '2021042420002',
--         '20',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410006',
--         '2021042420002',
--         '22',
--         '男'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410007',
--         '2021042420002',
--         '20',
--         '女'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410008',
--         '2021042420002',
--         '21',
--         '女'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410009',
--         '2021042420002',
--         '70'
--     );
-- INSERT INTO GRADE
-- VALUES(
--         '2021042410010',
--         '2021042420002',
--         '23'
--     );
-- CREATE OR REPLACE FUNCTION up_audit() RETURNS TRIGGER AS $$
--  BEGIN 
--  IF (TG_OP = 'DELETE') THEN
--     DELETE FROM GRADE WHERE SID = old.SID;
--     RETURN NEW;
--  ELSIF (TG_OP = 'UPDATE') THEN
--     UPDATE GRADE SET SID = NEW.SID WHERE SID = OLD.SID; 
--     RETURN NEW;
--  END IF;
--  RETURN NULL; 
-- END;
-- $$ LANGUAGE plpgsql;
-- CREATE TRIGGER up_audit_trigger
-- BEFORE UPDATE OR DELETE ON STUDENT
-- FOR EACH ROW EXECUTE PROCEDURE up_audit();
-- CREATE OR REPLACE FUNCTION Count1()
-- RETURNS integer AS $$
-- DECLARE
--     count integer;
-- BEGIN 
--     select count(*) into count from GRADE where CID = '2021042420001' and Score < 60 ;
--     RETURN count;
-- END;
-- $$ language plpgsql;