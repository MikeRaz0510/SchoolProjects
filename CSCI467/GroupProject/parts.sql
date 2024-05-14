USE z1696323;
DROP TABLE IF EXISTS  PARTSORDERED, PART, ORDERS, SHIPPING;

CREATE TABLE PART (PartNum int(5) NOT NULL UNIQUE PRIMARY KEY,
            PartName CHAR(50) NOT NULL,
            Description CHAR(100) NOT NULL, 
            Pic CHAR(50) NOT NULL,
            Weight int(10) NOT NULL,
            Price DECIMAL(6,2) NOT NULL,
            Available int(20) NOT NULL);


INSERT INTO PART VALUES (00001, 'Driver Door', 'Front door on the driver side.', 'https://i.imgur.com/fQm6Rzs.jpeg', 100, 199.99, 5);
INSERT INTO PART VALUES (00002, 'Passenger Door', 'Front door on the passenger side.', 'https://i.imgur.com/4N2xNE7.jpeg', 100, 199.99, 5);
INSERT INTO PART VALUES (00003, 'Wheel Hub', 'The hub that holds the tire.', 'https://i.imgur.com/G0bhFnM.jpeg', 20, 49.99, 8);
INSERT INTO PART VALUES (00004, 'Tire', 'Round and Rubber', 'https://i.imgur.com/MWYbCtw.jpeg', 15, 79.99, 20);
INSERT INTO PART VALUES (00005, 'Brake Pad', 'Makes the car stop', 'https://i.imgur.com/MYeTqxN.png', 5, 19.99, 24);
INSERT INTO PART VALUES (00006, 'Head light', 'Lights to illuminate the road in front', 'https://i.imgur.com/YRWF6cu.jpeg', 5, 24.99, 10);
INSERT INTO PART VALUES (00007, 'Brake light', 'Lights turn on when the brakes are applied', 'https://i.imgur.com/R4NarWO.jpeg', 5, 24.99, 10);
INSERT INTO PART VALUES (00008, 'Steering Wheel', 'So you can steer the car', 'https://i.imgur.com/kMgILBK.jpeg', 5, 74.99, 5);
INSERT INTO PART VALUES (00009, 'Radio', 'Provides entertainment for all occupants', 'https://i.imgur.com/JphwGeX.jpeg', 10, 99.99, 10);
INSERT INTO PART VALUES (00010, 'Trunk door', 'A door for the rear storage compartment', 'https://i.imgur.com/luMzV4u.jpeg', 50, 149.99, 5);

CREATE TABLE ORDERS (OrderNum int(5) NOT NULL UNIQUE PRIMARY KEY,
            CustName CHAR(50) NOT NULL,
            OrderDate DATE NOT NULL, 
            OrderSubTotal DECIMAL(7,2) NOT NULL,
            Status CHAR(10) NOT NULL,
            Email CHAR(50) NOT NULL,
            PhoneNum CHAR(14));

INSERT INTO ORDERS VALUES (00001, 'Matt', '2023-12-01', 199.99, 'COMPLETE', 'Matt@gmail.com', '(224)-974-3716'); --front door
INSERT INTO ORDERS VALUES (00002, 'Jenny', '2023-11-30',319.96 , 'COMPLETE', 'JenSmith@gmail.com', '(708)-491-1904'); --4 tires
INSERT INTO ORDERS VALUES (00003, 'Lee', '2023-11-28', 49.98, 'COMPLETE', 'LeeJ96@yahoo.com', '(847)-368-1073'); --2 head lights
INSERT INTO ORDERS VALUES (00004, 'Susan', '2023-12-05', 99.99, 'RECIEVED', 'Susan99@gmail.com', '(224)-193-5682'); -- radio
INSERT INTO ORDERS VALUES (00005, 'Bob', '2023-12-03', 224.98, 'SHIPPED', 'RobertGeorge@yahoo.com', '(312)-525-6678'); --trunk door and steering wheel

CREATE TABLE PARTSORDERED (OrderNum int(5) NOT NULL,
            PartNum int(5) NOT NULL,
            Quantity int(3) DEFAULT 1,
            PRIMARY KEY (OrderNum, PartNum),
            FOREIGN KEY (OrderNum) REFERENCES ORDERS(OrderNum),
            FOREIGN KEY (PartNum) REFERENCES PART(PartNum));

INSERT INTO PARTSORDERED VALUES (00001, 00001, 1);
INSERT INTO PARTSORDERED VALUES (00002, 00004, 4);
INSERT INTO PARTSORDERED VALUES (00003, 00006, 2);
INSERT INTO PARTSORDERED VALUES (00004, 00009, 1);
INSERT INTO PARTSORDERED VALUES (00005, 00010, 1);
INSERT INTO PARTSORDERED VALUES (00005, 00008, 1);


CREATE TABLE SHIPPING (BracketNum int(1) NOT NULL PRIMARY KEY UNIQUE,
            boxSize CHAR(10),
            MinWeight int(3),
            MaxWeight int(4),
            Price Decimal(7,2));

INSERT INTO SHIPPING VALUES(1,'Small', 0, 50, 4.99);
INSERT INTO SHIPPING VALUES(2,'Medium', 50, 100, 9.99);
INSERT INTO SHIPPING VALUES(3, 'Large', 100, 9999, 14.99);
