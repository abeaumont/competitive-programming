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
            let a = Array[Array[I32]](301)
            a.push(Array[I32].init(0, 301))
            for i in Range[USize](1, 301) do
              a.push(Array[I32].init(0, 301))
              for j in Range[USize](1, 301) do
                let r = j.i32() + 10
                let y = i.i32()
                a(i)?(j)? = (((((r*y)+n)*r)/100)%10)-5
              end
            end
            for i in Range[USize](1, 301) do
              for j in Range[USize](1, 301) do
                a(i)?(j)? = (a(i-1)?(j)? + a(i)?(j-1)? + a(i)?(j)?) - a(i-1)?(j-1)?
              end
            end
            var m = I32(0)
            var y = USize(0)
            var x = USize(0)
            var z = USize(0)
            for k in Range[USize](1, 300) do
              for i in Range[USize](1, 301 - k) do
                for j in Range[USize](1, 301 - k) do
                  let s = (a(i+k)?(j+k)? + a(i)?(j)?) - (a(i+k)?(j)? + a(i)?(j+k)?)
                  if s > m then
                    m = s
                    y = i
                    x = j
                    z = k
                  end
                end
              end
            end
            env.out.print((x + 1).string() + "," + (y + 1).string() + "," + z.string())
          end
      end,
      512)
