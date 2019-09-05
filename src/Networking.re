open ReactNative;

module FetchExample = {
    let inspect = (x) => {
        Js.log(x);
        x
    };

    let jsonExn = (f, x) => Belt.Option.getExn(f(x));

    type movie = {
        id: string,
        title: string,
        releaseYear: string,
    };

    let jsonToMovie = (obj) => {
        id: jsonExn(Js.Json.decodeString, Js.Dict.unsafeGet(obj, "id")),
        title: jsonExn(Js.Json.decodeString, Js.Dict.unsafeGet(obj, "title")),
        releaseYear: jsonExn(Js.Json.decodeString, Js.Dict.unsafeGet(obj, "releaseYear")),
    };

    let getMovies = (x) => {
        x
        |> jsonExn(Js.Json.decodeObject)
        |> Js.Dict.unsafeGet(_, "movies")
        |> jsonExn(Js.Json.decodeArray)
        |> Array.map(x => jsonToMovie(jsonExn(Js.Json.decodeObject, x)), _)
    };

    let renderItem = (obj) => <Text>{React.string(obj##item.title ++ ", " ++ obj##item.releaseYear)}</Text>;

    let keyExtractor = (obj, _index) => obj.id;

    [@react.component]
    let make = () => {
        let (data, updateData) = React.useState(() => None);
        React.useEffect0(() => {
            let _ = Js.Promise.(
                Fetch.fetch("https://facebook.github.io/react-native/movies.json")
                |> then_(Fetch.Response.json)
                |> then_((x) => resolve(updateData(_ => Some(getMovies(x)))))
            );
            None
        });

        switch data {
            | None => <View style=Style.(style(~flex=1., ~paddingTop=20.->dp, ()))><ActivityIndicator/></View>
            | Some(data) => {
                <View style=Style.(style(~flex=1., ~paddingTop=dp(20.), ()))>
                    <FlatList data renderItem keyExtractor/>
                </View>
            }
        }
    }
};
