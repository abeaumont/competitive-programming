#!/usr/bin/env elixir
defmodule Day18 do
  def add([], ys), do: ys

  def add(xs, ys) do
    reduce([xs, ys])
  end

  def reduce(t) do
    case explode(t, 0) do
      {true, t, _, _} ->
        reduce(t)

      {false, t} ->
        case split(t) do
          {true, t} ->
            reduce(t)

          {false, t} ->
            t
        end
    end
  end

  def explode([fst, snd], 4), do: {true, 0, fst, snd}

  def explode([fst, snd], d) do
    case explode(fst, d + 1) do
      {true, t, l, 0} ->
        {true, [t, snd], l, 0}

      {true, t, l, r} ->
        {true, [t, addl(snd, r)], l, 0}

      {false, _} ->
        case explode(snd, d + 1) do
          {true, t, 0, r} -> {true, [fst, t], 0, r}
          {true, t, l, r} -> {true, [addr(fst, l), t], 0, r}
          {false, _} -> {false, [fst, snd]}
        end
    end
  end

  def explode(x, _), do: {false, x}

  def split([fst, snd]) do
    case split(fst) do
      {true, t} ->
        {true, [t, snd]}

      {false, _} ->
        case split(snd) do
          {true, t} -> {true, [fst, t]}
          {false, _} -> {false, [fst, snd]}
        end
    end
  end

  def split(x) when x >= 10, do: {true, [div(x, 2), div(x + 1, 2)]}
  def split(x), do: {false, x}

  def addl([fst, snd], n), do: [addl(fst, n), snd]
  def addl(x, n), do: x + n

  def addr([fst, snd], n), do: [fst, addr(snd, n)]
  def addr(x, n), do: x + n

  def magnitude([fst, snd]), do: 3 * magnitude(fst) + 2 * magnitude(snd)
  def magnitude(x), do: x
end

IO.read(:stdio, :all)
|> String.split("\n")
|> Enum.filter(fn x -> String.length(x) > 1 end)
|> Enum.map_reduce([], fn x, acc ->
  sum = Day18.add(acc, elem(Code.eval_string(x), 0))
  {sum, sum}
end)
|> elem(1)
|> Day18.magnitude()
|> IO.puts()
