
/*
Mike Rasmussen
z1696323
466-PE1
3/8/23"
*/
-- 1.
USE BabyName;					-- select the BabyName database 

-- 2.
SHOW TABLES;		-- list all of the tables 

-- 3.
SELECT DISTINCT name, year 		-- Only show each name once
FROM BabyName					-- from the babyname table 
WHERE year = 1995
LIMIT 50;				-- Only from the year 1995

-- 4.
DESCRIBE BabyName;			-- show each column and their data types

-- 5.
SELECT place, 			-- show all places 
COUNT(DISTINCT name)		-- show the number of unique names
FROM BabyName;

-- 6.
SELECT DISTINCT year, name 		-- show the year and names
FROM BabyName					-- From the BabyName table 
Where name = 'Mike'				-- whenever there is a name mike
LIMIT 50;

-- 7.
SELECT name, gender, year, count 		-- show name, gender, year, and count
FROM BabyName 							-- from the BabyName database
WHERE count = 							
	( SELECT MAX(count) 				-- Where count is the max
	  FROM BabyName 	
	  WHERE year = 1984					-- in the year 1984
	)
GROUP BY gender; 						-- group results by gender
SELECT name, gender, year, count 		-- show name gender year and count
FROM BabyName 							-- from the BabyName database
WHERE count = 
	( SELECT MAX(count) 
	  FROM BabyName 					-- where count is the max
	  WHERE year = 1984 				-- in the year 1984
	  AND gender = 'F'					-- and gender is female
	)
GROUP BY gender;						-- group results by gender


-- 8.
SELECT *						-- show all data 
FROM BabyName						-- from BabyName
WHERE name LIKE 'Mik%'					-- Show all names similar to Mike
ORDER BY name ASC, count, year				-- Sort by name, then count, then year  
LIMIT 50;

-- 9.
SELECT year, COUNT(DISTINCT name)		-- show the year and number of unique names  
FROM BabyName					-- from the babyname database 
Where year = 1946;				-- in the year 1946


-- 10.
SELECT Count(name)		-- count all names (there will be 1 row for each name 
FROM BabyName;			-- from the babyname database 

-- 11.
SELECT COUNT(DISTINCT name), gender, year		-- show the count of names, the gender and the year 
FROM BabyName 									-- from babyname database 
WHERE year = 1968								-- in the year 1968
GROUP BY gender;								-- and group them by gender 

-- 12.
SELECT DISTINCT LEFT(name,1) AS First_Letter, COUNT(*) AS Frequency	-- Show the first letter of every name and their count
FROM BabyName								-- From the babyname database
GROUP BY First_Letter;							-- group the data by the First Letter

