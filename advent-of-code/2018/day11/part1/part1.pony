use "collections"

actor Main
  new create(env: Env) =>
    env.input(
      object iso is InputNotify
        fun ref apply(data: Array[U8] iso) =>
          try
            let line = String.from_iso_array(consume data)
            line.strip()
            let n = line.i32()?
            let a = Array[Array[I32]](300)
            for i in Range[USize](0, 300) do
              a.push(Array[I32].init(0, 300))
              for j in Range[USize](0, 300) do
                let r = j.i32() + 11
                let y = i.i32() + 1
                a(i)?(j)? = (((((r*y)+n)*r)/100)%10)-5
              end
            end
            var m = I32(0)
            var y = USize(0)
            var x = USize(0)
            for i in Range[USize](0, 298) do
              for j in Range[USize](0, 298) do
                var s = I32(0)
                for k in Range[USize](i, i+3) do
                  for l in Range[USize](j, j+3) do
                    s = s + a(k)?(l)?
                    if s > m then
                      m = s
                      y = i
                      x = j
                    end
                  end
                end
              end
            end
            env.out.print((x + 1).string() + "," + (y + 1).string())
          end
      end,
      512)
