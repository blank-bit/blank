CREATE DATABASE BookSale;
--图书信息表(BOOK)、销售信息表(SALE)
--视图-库存表(STOCK);
CREATE TABLE BOOK_2019091601025(
    BookID CHAR(10) NOT NULL,
    BookName VARCHAR(20) NOT NULL,
    Author VARCHAR(10) NOT NULL,
    Publisher VARCHAR(10) NOT NULL,
    PublishDate Date NOT NULL,
    Price Money NOT NULL,
    -- StockNumber INT NOT NULL,
    CONSTRAINT BookID_PK PRIMARY KEY(BookID)
);
create unique index BookID_idx on BOOK_2019091601025 (BookID);
CREATE TABLE SALE_2019091601025(
    SaleID CHAR(10) NOT NULL,
    BookID CHAR(10) NOT NULL,
    BookName VARCHAR(20) NOT NULL,
    RealSalePrice Money NOT NULL,
    SaleNumber INT NOT NULL,
    SaleDate Date NOT NULL,
    CONSTRAINT SaleID_idx PRIMARY KEY(SaleID),
    CONSTRAINT BookID_FK FOREIGN KEY(BookID) REFERENCES BOOK_2019091601025(BookID) ON DELETE CASCADE
);
create unique index SaleID_PK on SALE_2019091601025 (SaleID);
create index BookID_FK on SALE_2019091601025 (BookID);
CREATE TABLE STOCK_2019091601025(
    BookID CHAR(10) NOT NULL,
    BookName VARCHAR(20) NOT NULL,
    StockNumber INT NOT NULL
);
create index SaleDate_idx on STOCK_2019091601025 (SaleDate);
create index StockNumber_idx on STOCK_2019091601025 (StockNumber);
INSERT INTO BOOK_2019091601025
VALUES(
        '2105101001',
        '神谷',
        '霍瑟夫',
        '华府出版社',
        '2001-09-22',
        '55'
    );
INSERT INTO BOOK_2019091601025
VALUES(
        '2105101002',
        '烟灰色的天空',
        '埃拉斯',
        '任誊出版社',
        '2011-03-12',
        '55'
    );
INSERT INTO SALE_2019091601025
VALUES(
        '2105102001',
        '2105101001',
        '神谷',
        '50',
        '3',
        '2021-03-12'
    );
INSERT INTO SALE_2019091601025
VALUES(
        '2105102002',
        '2105101002',
        '烟灰色的天空',
        '65',
        '2',
        '2021-03-13'
    );
INSERT INTO STOCK_2019091601025
VALUES(
        '2105101001',
        '神谷',
        '250'
    );
INSERT INTO STOCK_2019091601025
VALUES(
        '2105101002',
        '烟灰色的天空',
        '50'
    );
CREATE VIEW Book_Author_Publisher_2019091601025 AS
SELECT B.BookName AS "书名",
    B.Author AS "作者",
    B.Publisher AS "出版社",
    B.Price AS "价格",
    S.StockNumber AS "库存"
FROM BOOK_2019091601025 AS B
    JOIN STOCK_2019091601025 AS S ON B.BookID = S.BookID;
SELECT *
FROM Book_Author_Publisher_2019091601025;
CREATE OR REPLACE FUNCTION Pro_CurrentSale_2019091601025(OUT count integer, OUT totalmoney money) RETURNS RECORD AS $$ BEGIN
select SUM(SaleNumber) into count
from SALESALE_2019091601025
where SaleDate = '2021-03-12';
select SUM(RealSalePrice) into totalmoney
from SALESALE_2019091601025
where SaleDate = '2021-03-12';
END;
$$ language plpgsql;
CREATE OR REPLACE FUNCTION Tri_InsertSale() RETURNS TRIGGER AS $$ BEGIN
UPDATE STOCK_2019091601025
SET StockNumber = StockNumber - NEW.SaleNumber
WHERE BookID = NEW.BookID;
RETURN NEW;
END;
$$ LANGUAGE plpgsql;
CREATE TRIGGER Tri_InsertSale_trigger
AFTER
INSERT ON SALE_2019091601025 FOR EACH ROW EXECUTE PROCEDURE Tri_InsertSale();
CREATE OR REPLACE FUNCTION Pro_AllSale_2019091601025(OUT count integer, OUT totalmoney money) RETURNS RECORD AS $$ BEGIN
select SUM(SaleNumber) into count
from SALE_2019091601025;
select SUM(RealSalePrice) into totalmoney
from SALE_2019091601025;
END;
$$ language plpgsql;
CREATE ROLE "R_Customer_2019091601025" WITH LOGIN CONNECTION
LIMIT -1;
CREATE ROLE "R_Seller_2019091601025" WITH LOGIN CONNECTION
LIMIT -1;
GRANT SELECT,
    INSERT,
    UPDATE,
    DELETE ON BOOK_2019091601025 TO "R_Seller_2019091601025";
GRANT SELECT,
    INSERT,
    UPDATE,
    DELETE ON SALE_2019091601025 TO "R_Seller_2019091601025";
GRANT SELECT,
    INSERT,
    UPDATE,
    DELETE ON STOCK_2019091601025 TO "R_Seller_2019091601025";
GRANT SELECT ON BOOK_2019091601025 TO "R_Customer_2019091601025";
CREATE USER "U_Customer_2019091601025" WITH LOGIN INHERIT CONNECTION
LIMIT -1 PASSWORD '123456';
CREATE USER "U_Seller_2019091601025" WITH LOGIN INHERIT CONNECTION
LIMIT -1 PASSWORD '123456';
GRANT "R_Seller_2019091601025" TO "U_Seller_2019091601025";
GRANT "R_Customer_2019091601025" TO "U_Customer_2019091601025";
select *
from stock_2019091601025;
INSERT INTO SALE_2019091601025
VALUES(
        '2105132004',
        '2105101002',
        '烟灰色的天空',
        '100',
        '2',
        '2021-03-13'
    );
UPDATE BOOK_2019091601025
SET PRICE = '49'
WHERE BookID = '2105101001';
DELETE FROM SALE_2019091601025
WHERE SALEID = '2105132004'