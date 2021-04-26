-- CREATE TABLE CLIENT (
--     ClientID CHAR(13) NOT NULL,
--     ClientName VARCHAR(10) NOT NULL,
--     ClientGender CHAR(2) NULL,
--     ClientPID CHAR(18) NOT NULL,
--     ClientTel VARCHAR(11) NOT NULL,
--     CONSTRAINT ClientID_PK PRIMARY KEY(ClientID)
-- );
-- INSERT INTO CLIENT
-- VALUES(
--         '2021042410001',
--         '刘夏花',
--         '女',
--         '34653519970924789X',
--         '17777777777'
--     );
-- INSERT INTO CLIENT
-- VALUES(
--         '2021042410002',
--         '景汇丰',
--         '男',
--         '346535197609214362',
--         '15468822358'
--     );
-- CREATE TABLE CAR (
--     CarID CHAR(13) NOT NULL,
--     CarBrand VARCHAR(10) NOT NULL,
--     CarModel VARCHAR(10) NOT NULL,
--     CarSeat VARCHAR(3) NOT NULL,
--     CONSTRAINT CarID_PK PRIMARY KEY(CarID)
-- );
-- INSERT INTO CAR
-- VALUES('2021042420001', '奔驰', 'E级AMG', '5');
-- INSERT INTO CAR
-- VALUES('2021042420002', '五菱', '宏光mini EV', '5');
-- CREATE TABLE RENT_PRICE (
--     CarID CHAR(13) NOT NULL,
--     RentPrice MONEY NOT NULL,
--     CONSTRAINT CarID_FK FOREIGN KEY(CarID) REFERENCES CAR(CarID) ON DELETE CASCADE
-- );
-- INSERT INTO RENT_PRICE
-- VALUES('2021042420001', '500');
-- INSERT INTO RENT_PRICE
-- VALUES('2021042420002', '250');
-- CREATE TABLE RENT_REG (
--     RegID SERIAL NOT NULL,
--     ClientID CHAR(13) NOT NULL,
--     CarID CHAR(13) NOT NULL,
--     RentDate DATE NOT NULL,
--     ReturnDate DATE NOT NULL,
--     CONSTRAINT RegID_PK PRIMARY KEY(RegID)
-- );
-- INSERT INTO RENT_REG
-- VALUES(
--         DEFAULT,
--         '2021042410001',
--         '2021042420001',
--         '2021-04-02',
--         '2021-04-03'
--     );
-- INSERT INTO RENT_REG
-- VALUES(
--         DEFAULT,
--         '2021042410002',
--         '2021042420002',
--         '2021-03-23',
--         '2021-04-01'
--     );
-- CREATE TABLE RENT_FEE(
--     FeeID SERIAL NOT NULL,
--     ClientID CHAR(13) NOT NULL,
--     CarID CHAR(13) NOT NULL,
--     RentDays INTEGER,
--     RentPrice MONEY NOT NULL,
--     TotalFee MONEY NOT NULL,
--     CONSTRAINT FeeID_PK PRIMARY KEY(FeeID)
-- )
-- INSERT INTO RENT_FEE
-- VALUES(
--         DEFAULT,
--         '2021042410001',
--         '2021042420001',
--         '1',
--         '500',
--         '500'
--     );
-- INSERT INTO RENT_FEE
-- VALUES(
--         DEFAULT,
--         '2021042410002',
--         '2021042420002',
--         '8',
--         '250',
--         '2000'
--     );
-- CREATE ROLE "R_Client" WITH
-- LOGIN
-- CONNECTION LIMIT -1;
-- CREATE ROLE "R_SalesMan" WITH
-- LOGIN
-- CONNECTION LIMIT -1;
-- CREATE ROLE "R_Manager" WITH
-- LOGIN
-- CONNECTION LIMIT -1;
-- CREATE ROLE "R_Adminstrator" WITH
-- LOGIN
-- CONNECTION LIMIT -1;
-- GRANT SELECT,INSERT,UPDATE,DELETE ON CLIENT TO "R_Manager";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON CAR TO "R_Manager";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON RENT_PRICE TO "R_Manager";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON RENT_REG TO "R_Manager";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON RENT_FEE TO "R_Manager"
-- GRANT SELECT,INSERT,UPDATE,DELETE ON CLIENT TO "R_Adminstrator";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON CAR TO "R_Adminstrator";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON RENT_PRICE TO "R_Adminstrator";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON RENT_REG TO "R_Adminstrator";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON RENT_FEE TO "R_Adminstrator"
-- GRANT SELECT,UPDATE ON CLIENT TO "R_Client";
-- GRANT SELECT ON CAR TO "R_Client";
-- GRANT SELECT ON RENT_PRICE TO "R_Client";
-- GRANT SELECT ON RENT_REG TO "R_Client";
-- GRANT SELECT ON RENT_FEE TO "R_Client"
-- GRANT SELECT ON CLIENT TO "R_SalesMan";
-- GRANT SELECT ON CAR TO "R_SalesMan";
-- GRANT SELECT ON RENT_PRICE TO "R_SalesMan";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON RENT_REG TO "R_SalesMan";
-- GRANT SELECT,INSERT,UPDATE,DELETE ON RENT_FEE TO "R_SalesMan"
-- CREATE USER "ClientUser" WITH
-- LOGIN
-- INHERIT
-- CONNECTION LIMIT -1
-- PASSWORD '123456';
-- CREATE USER "SalesManUser" WITH
-- LOGIN
-- INHERIT
-- CONNECTION LIMIT -1
-- PASSWORD '123456';
-- CREATE USER "ManagerUser" WITH
-- LOGIN
-- INHERIT
-- CONNECTION LIMIT -1
-- PASSWORD '123456';
-- CREATE USER "AdminstratorUser" WITH
-- LOGIN
-- INHERIT
-- CONNECTION LIMIT -1
-- PASSWORD '123456';
-- GRANT "R_Client" TO "ClientUser";
-- GRANT "R_SalesMan" TO "SalesManUser";
-- GRANT "R_Manager" TO "ManagerUser";
-- GRANT "R_Adminstrator" TO "AdminstratorUser";
psql - h 127.0.0.1
select *
from car \ g
select *
from client \ g
select *
from rent_price \ g
select *
from rent_fee \ g
select *
from rent_reg \ g
update car
set carmodel = '奥迪'
where carid = '2021042420002' \ g
update client
set clienttel = '12345678901'
where clientid = '2021042410002' \ g
update rent_price
set rentprice = '300'
where carid = '2021042420002' \ g
update rent_reg
set returndate = '2021-04-24'
where carid = '2021042420002' \ g
update rent_fee
set rentdays = '10'
where carid = '2021042420002' \ g
INSERT INTO CLIENT
VALUES(
        '2021042410003',
        '胡洋洋',
        '女',
        '34653519450920789X',
        '13456678935'
    );
INSERT INTO CAR
VALUES('2021042420003', '大众', '帕萨特', '5');
INSERT INTO RENT_PRICE
VALUES('2021042420003', '700');
INSERT INTO RENT_REG
VALUES(
        DEFAULT,
        '2021042410003',
        '2021042420003',
        '2021-04-06',
        '2021-04-11'
    );
INSERT INTO RENT_FEE
VALUES(
        DEFAULT,
        '2021042410003',
        '2021042420003',
        '5',
        '700',
        '3500'
    );
delete from car
where carid = '2021042420003' \ g
delete from client
where clientid = '2021042410003' \ g
delete from rent_price
where carid = '2021042420003' \ g
delete from rent_reg
where carid = '2021042420003' \ g
delete from rent_fee
where carid = '2021042420003' \ g