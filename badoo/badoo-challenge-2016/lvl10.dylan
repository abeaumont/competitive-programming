module: lvl10
// Minimal solution for level 10. The problem was so hard that it was
// not possible to implement an algorithm with the optimal solution,
// not at least with the scarce remaining time, so went through a dummy
// solution that is able to solve the example, test and final cases and
// sketches the overall OOP design with multimethods.

define generic cost(resource);
define method cost(resource) 1 end;
define method cost(resource == #"TownHall") 1100 end;
define method cost(resource == #"Barracks") 200 end;
define method cost(resource == #"ArcheryRange") 290 end;
define method cost(resource == #"Peasant") 50 end;
define method cost(resource == #"Soldier") 50 end;
define method cost(resource == #"Archer") 55 end;

define generic turns(resource);
define method turns(resource) 0 end;
define method turns(resource == #"Peasant") 3 end;
define method turns(resource == #"Soldier") 4 end;
define method turns(resource == #"Archer") 3 end;

define function additional-resources(final, initial, resource)
  if (resource.first = #"ArcheryRange" & element(initial, #"Barrack", default: #f))
    add(final, pair(#"Barrack", 1));
  else
    final;
  end if;
end function additional-resources;

define function best(cost, initial-peasants, final-peasants)
  local method turns(peasants)
          let new-peasants = (peasants - initial-peasants);
          let total-cost = cost + 5 * new-peasants;
          for (i from initial-peasants below peasants)
            total-cost := total-cost - i * 3;
          end for;
          ceiling/(total-cost, peasants) + new-peasants * 3
        end method turns,
        method loop(best, peasants)
          let next = turns(peasants);
          if (next > best)
            best
          else
            loop(next, peasants + 1);
          end if;
        end method loop;
  loop(turns(initial-peasants), initial-peasants + 1)
end function best;

define function main()
  let ir = string-to-integer(read-line(*standard-input*));
  let initial-resources = make(<table>, size: ir);
  for (i from 0 below ir)
    let resource = split(read-line(*standard-input*), " ");
    initial-resources[as(<symbol>, resource[0])] := string-to-integer(resource[1]);
  end for;
  let fr = string-to-integer(read-line(*standard-input*));
  let final-resources = make(<list>);
  for (i from 0 below fr)
    let resource = split(read-line(*standard-input*), " ");
    final-resources := add(final-resources, pair(as(<symbol>, resource[0]), string-to-integer(resource[1])));
    final-resources := additional-resources(final-resources, initial-resources, resource);
  end for;
  let total-cost = 0;
  let total-turns = 0;
  let final-peasants = 0;
  for(resource in final-resources)
    let initial = element(initial-resources, resource.head, default: 0);
    if (resource.head = #"Peasant")
      final-peasants := resource.tail;
    else
      total-cost := total-cost + (resource.tail - initial) * cost(resource.head)
    end if;
    total-turns := total-turns + (resource.tail - initial) * turns(resource.head);
  end for;
  let score = string-to-integer(read-line(*standard-input*));
  let best = best(floor/(total-cost, 10), element(initial-resources, #"Peasant", default: 0), final-peasants);
  if (best > score | total-turns > score)
    format-out("CHEATER\n");
  else
    format-out("%=\n", score - best);
  end if;
end function main;

main();
