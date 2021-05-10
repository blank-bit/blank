CREATE DATABASE BookSale;
--图书信息表(BOOK)、销售信息表(SALE)
--视图-库存表(STOCK);
CREATE TABLE BOOK(
    BookID CHAR(10) NOT NULL,
    BookName VARCHAR(20) NOT NULL,
    Author VARCHAR(10) NOT NULL,
    Publisher VARCHAR(10) NOT NULL,
    PublishDate Date NOT NULL,
    Purchase Money NOT NULL,
    Price Money NOT NULL,
    StockNumber INT NOT NULL,
    CONSTRAINT BookID_PK PRIMARY KEY(BookID)
);
CREATE TABLE SALE(
    SaleID CHAR(10) NOT NULL,
    BookID CHAR(10) NOT NULL,
    RealSaleNum Money NOT NULL,
    SaleDate Date NOT NULL,
    CONSTRAINT SaleID_PK PRIMARY KEY(SaleID),
    CONSTRAINT BookID_FK FOREIGN KEY(BookID) REFERENCES BOOK(BookID) ON DELETE CASCADE
);
INSERT INTO BOOK
VALUES(
        '2105101001',
        '神谷',
        '霍瑟夫',
        '华府出版社',
        '2001-09-22',
        '35',
        '55',
        '300'
    );
INSERT INTO BOOK
VALUES(
        '2105101002',
        '烟灰色的天空',
        '埃拉斯',
        '任誊出版社',
        '2011-03-12',
        '35',
        '55',
        '250'
    );
INSERT INTO SALE
VALUES(
        '2105102001',
        '2105101001',
        '50',
        '2021-03-12'
    );