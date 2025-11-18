create table routes
( point1 varchar not null,
  point2 varchar not null,
  cost integer not null
  );

 insert into routes(point1,point2,cost) values('a','b',10);
 insert into routes(point1,point2,cost) values ('b','a',10);
 insert into routes(point1,point2,cost) values ('a','d',20);
 insert into routes(point1,point2,cost) values ('d','a',20);
 insert into routes(point1,point2,cost) values  ('a','c',15);
 insert into routes(point1,point2,cost) values ('c','a',15);
 insert into routes(point1,point2,cost) values ('b','c',35);
 insert into routes(point1,point2,cost) values ('c','b',35);
 insert into routes(point1,point2,cost) values ('b','d',25);
 insert into routes(point1,point2,cost) values('d','b',25);
 insert into routes(point1,point2,cost) values('d','c',30);
 insert into routes(point1,point2,cost) values('c','d',30);

