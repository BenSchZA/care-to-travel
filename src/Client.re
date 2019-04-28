/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(~uri="https://care-to-travel-bf8357556e.herokuapp.com/CareToTravel/dev", ());

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());