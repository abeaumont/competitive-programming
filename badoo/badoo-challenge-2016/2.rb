#!/usr/bin/ruby
require 'date'

events = []
(1..gets.to_i).each do
  entry, exit = gets.split(' - ').map{|x| DateTime.parse(x) }
  time = ((exit - entry) * 24 * 3600).to_i
  cost = 2.0
  if time > 3600 then
    cost += 0.5 * ((time - 3600) / (15 * 60.0)).ceil
  end
  events.push([entry, 1, 0], [exit, 0, cost])
end

current_cars = 0
daily_max = 0
peak_max = 0
peak_day = nil
daily_total = 0
total = 0
current_day = nil
days = {}
events.sort.each do |event|
  time, type, cost = event
  day = time.strftime("%d.%m.%Y")
  if day == current_day then
    if type == 0 then
      daily_max = [daily_max, current_cars].max
      current_cars -= 1
      daily_total += cost
    else
      current_cars += 1
      daily_max = [daily_max, current_cars].max
    end
  else
    if not current_day.nil? then
      if daily_total > 0 then
        daily_max = [daily_max, current_cars].max
        days[current_day] = [daily_max, daily_total]
        total += daily_total
      end
      if peak_max < daily_max then
        peak_max = daily_max
        peak_day = current_day
      end
    end
    current_day = day
    daily_total = 0
    daily_max = 0
    if type == 0 then
      daily_max = [daily_max, current_cars].max
      current_cars -= 1
      daily_total += cost
    else
      current_cars += 1
      daily_max = [daily_max, current_cars].max
    end
  end
end
if daily_total > 0 then
  daily_max = [daily_max, current_cars].max
  days[current_day] = [daily_max, daily_total]
  total += daily_total
end
if peak_max < daily_max then
  peak_max = daily_max
  peak_day = current_day
end

days.each do |key, value|
  max, tot = value
  puts "#{key} #{max} #{tot}"
end
puts "PEAK #{peak_max} AT #{peak_day}"
puts "TOTAL #{total}"
