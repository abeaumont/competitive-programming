program part1;

uses
types,
sysutils,
strutils;

type TBoard = array[0..4] of array[0..4] of integer;

function mark(var b: TBoard; n: integer): boolean;
var i, j : integer;
begin
   for i := 0 to 4 do
      for j := 0 to 4 do
         if b[i][j] = n then
         begin
            b[i][j] := -1;
            exit(true);
         end;
   exit(false);
end;

function check(const b: TBoard): boolean;
var
   ok  : boolean;
   i,j : integer;
begin
   for i := 0 to 4 do
   begin
      ok := true;
      for j := 0 to 4 do
         if b[i][j] >= 0 then
         begin
            ok := false;
            break;
         end;
      if ok then
         exit(true);
   end;
   for i := 0 to 4 do
   begin
      ok := true;
      for j := 0 to 4 do
         if b[j][i] >= 0 then
         begin
            ok := false;
            break;
         end;
      if ok then
         exit(true);
   end;
   exit(false);
end;

function sum(const b: TBoard): integer;
var i, j : integer;
begin
   sum := 0;
   for i := 0 to 4 do
      for j := 0 to 4 do
         if b[i][j] >= 0 then
            sum := sum + b[i][j];
end;

var
   board          : TBoard;
   numbers        : array of integer;
   i, n, max, ans : integer;
   line           : string;
   fields         : TStringDynArray;
begin
   readln(line);
   fields := splitString(line, ',');
   n := length(fields);
   max := -1;
   setLength(numbers, n);
   for i := 0 to n - 1 do
      numbers[i] := StrToInt(fields[i]);
   while not eof do
   begin
      readln;
      for i := 0 to 4 do
         readln(board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
      for i := 0 to n - 1 do
         if mark(board, numbers[i]) then
            if check(board) then
            begin
               if i > max then
               begin
                  max := i;
                  ans := sum(board);
               end;
               break;
            end;
   end;
   writeln(numbers[max] * ans);
end.
