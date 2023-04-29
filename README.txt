*** Usage message ***
USAGE: dbyload {-n|-u} database table file specfile [options]
options:
  -s separator
  -l nolog (not used)
  -b binary (not used)


*** head Test.csv ***
10000|TEST|1 CUP|200|5.0


*** Specification file Test.spec ***
Fid|Fname|Fserving|Fsodium|Ffiber


*** insert script created with dbyload -n ...  ***
USE nutrition;

LOAD DATA LOCAL INFILE 'Test.csv'
 INTO TABLE `food`
 FIELDS TERMINATED BY '|'
 LINES TERMINATED BY '\n'
 (`Fid` ,`Fname` ,`Fserving` ,`Fsodium` ,`Ffiber`);

SELECT 'Inserted', ROW_COUNT();


*** update script created with dbyload -u ...  ***
USE nutrition;

DROP TABLE IF EXISTS temp_food;

CREATE TEMPORARY TABLE temp_food SELECT `Fid`, `Fname`, `Fserving`, `Fsodium`, `Ffiber` FROM food LIMIT 0;

LOAD DATA LOCAL INFILE 'Test.csv'
 INTO TABLE temp_food FIELDS TERMINATED BY '|' (`Fid`, `Fname`, `Fserving`, `Fsodium`, `Ffiber`);

UPDATE food
 INNER JOIN temp_food on temp_food.Fid = food.Fid
 SET food.Fname = temp_food.Fname,
 food.Fserving = temp_food.Fserving,
 food.Fsodium = temp_food.Fsodium,
 food.Ffiber = temp_food.Ffiber;

SELECT 'Updated', ROW_COUNT();

DROP TEMPORARY TABLE temp_food;

