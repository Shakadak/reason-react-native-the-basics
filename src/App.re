open ReactNative;

[@bs.val] external alert : string => unit = "alert" ;

let styles = Style.(StyleSheet.create({
    "container": style(~flex=1., ~paddingTop=dp(22.), ()),
    "item": style(~padding=dp(10.), ~fontSize=18., ~height=dp(44.), ()),
}));

module FlatListBasics = {
    type name = {
        key: string,
    };
    let data : array(name) = [|
        {key: "Devin"},
        {key: "Dan"},
        {key: "Dominic"},
        {key: "Jackson"},
        {key: "James"},
        {key: "Joel"},
        {key: "John"},
        {key: "Jillian"},
        {key: "Jimmy"},
        {key: "Julie"},
    |];

    let keyExtractor = (item, _index) => item.key;

    let renderItem = (item) => <Text style=styles##item>{React.string(item##item.key)}</Text>;

    [@react.component]
    let make = () => {
        <View style=styles##container>
            <FlatList data keyExtractor renderItem/>
        </View>
    }
}

[@react.component]
let app = () => {
        <FlatListBasics/>
};
